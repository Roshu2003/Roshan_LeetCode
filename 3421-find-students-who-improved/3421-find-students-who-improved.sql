WITH ranked AS (
    SELECT
        student_id,
        subject,
        score,
        exam_date,
        FIRST_VALUE(score) OVER (
            PARTITION BY student_id, subject
            ORDER BY exam_date
        ) AS first_score,

        LAST_VALUE(score) OVER (
            PARTITION BY student_id, subject
            ORDER BY exam_date
            ROWS BETWEEN UNBOUNDED PRECEDING
            AND UNBOUNDED FOLLOWING
        ) AS latest_score

    FROM Scores
)

SELECT DISTINCT
    student_id,
    subject,
    first_score,
    latest_score
FROM ranked
WHERE latest_score > first_score
ORDER BY student_id, subject;