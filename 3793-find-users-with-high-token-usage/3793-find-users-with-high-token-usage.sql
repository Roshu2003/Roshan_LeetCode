# Write your MySQL query statement below
select user_id,count(prompt) prompt_count,round(AVG(tokens),2) avg_tokens 
from prompts
group by user_id
having count(prompt) > 2 and max(tokens) > AVG(tokens)
order by avg_tokens DEsc,user_id